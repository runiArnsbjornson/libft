#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <limits.h>
#include <assert.h>

int		numberbits(unsigned int valeur)
{
	int				ret;
	unsigned int	mask;

	ret = 0;
	mask = 1;
	if (valeur < 2)
		return (1);
	while (valeur >= mask)
	{
		++ret;
		mask <<= 1;
		if (mask == 0)
			return (CHAR_BIT * sizeof(valeur));
	}
	return (ret);
}

/*Ajoute un caractère dans un buffer, décalant l'index vers le début*/
void		push_char(char* buffer, size_t *pIndex, char ch)
{
	assert(buffer != NULL);
	assert(pIndex != NULL);

	if (*pIndex == 0)
		return ;
	-- *pIndex;
	buffer[*pIndex] = ch;
}

void		push_uchar(char* buffer, size_t *pIndex, unsigned char ch)
{
	push_char(buffer, pIndex, (char)ch);
}

char		*conversion_utf8(char* buffer, size_t cchTailleBuffer, int codePoint)
{
	/*Indications sur le premier octet de la séquence*/
	const int BitsUtilesDansPremierOctet[] = { 7, 5, 4, 3 };
	const unsigned char MasquePremierOctet[] = { 0x7F, 0x1F, 0x0F, 0x07 }; /*CORRECTION: Changer dernière valeur de 3 à 7*/
	const unsigned char PrefixePremierOctet[] = { 0x00, 0xC0, 0xE0, 0xF0 };
	const int MaxHexetsPlus1 = sizeof MasquePremierOctet / sizeof MasquePremierOctet[0];
	const size_t TailleMaxRequise = MaxHexetsPlus1 + 1; /*Un premier octet, 0-3 hexets, et un caractère nul terminal*/

	size_t index = cchTailleBuffer;
	unsigned int bitsCodePoint = codePoint;
	int nbTotalBits = numberbits(bitsCodePoint);
	int nbBitsRestants = nbTotalBits;
	int nbHexetsEcrits = 0;

	if (buffer == NULL || cchTailleBuffer < TailleMaxRequise)
		return NULL; /*Buffer trop petit pour taille maximale d'un codePoint UTF-8*/
	if (codePoint < 0 || nbTotalBits > 21)
		return NULL; /*codePoint hors plage*/

	/* On remplit le buffer en commençant par la fin */
	push_char(buffer, &index, '\0');

	while(nbBitsRestants > BitsUtilesDansPremierOctet[nbHexetsEcrits])
	{
		/*La valeur est trop grande pour entrer dans le premier octet: On ajoute ses six bits de poids faible à la fin.*/
		const unsigned int MasqueHexet = 0x0000003F;
		const unsigned char PrefixeHexet = 0x80;
		unsigned int bitsHexet = bitsCodePoint & MasqueHexet;
		unsigned char hexet = (unsigned char)(bitsHexet) | PrefixeHexet;
		push_uchar(buffer, &index, hexet);

		++nbHexetsEcrits;
		bitsCodePoint >>= 6;
		nbBitsRestants -= 6;
		assert(nbHexetsEcrits < MaxHexetsPlus1);
	}

	/*Et maintenant le premier octet*/
	{
		unsigned int bitsPremierOctet = bitsCodePoint & MasquePremierOctet[nbHexetsEcrits];
		unsigned char premierOctet = (unsigned char)bitsPremierOctet | PrefixePremierOctet[nbHexetsEcrits];
		push_uchar(buffer, &index, premierOctet);
	}

	/*Retourne le début de la partie 'écrite' dans le buffer*/
	return buffer + index;
}

int	main()
{
	int i;
	wchar_t *chn = L"bon alors ∑§§§±ß¥îé et voilà\n";
	char buffer[8];
	char *uchar;

	setlocale(LC_ALL, "");
	i = 0;
	while (chn[i])
	{
		if (chn[i] >= 127){
			uchar = conversion_utf8(buffer, 8, chn[i]);
			write(1, uchar, strlen(uchar));
		}
		else
			write(1, &chn[i], 1);
		i++;
	}
	wprintf(L"%S\n", chn);
	return 0;
}
