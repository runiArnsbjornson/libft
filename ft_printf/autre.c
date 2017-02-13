#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

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

void TestUtf8(int codePoint)
{
	char buffer[8];
	char* chn = conversion_utf8(buffer, sizeof buffer / sizeof buffer[0], codePoint);

	/*Ici, chn contient le texte qu'il te faut. Et il pointe à l'intérieur de buffer.*/
	static const char* bin4[] = { "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
	 "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" };
	size_t i;
	if(chn == NULL) { printf("conversion_utf8 a retourné NULL pour %d\n", codePoint); return; }

	/*La console Windows n'étant pas compatible avec UTF-8, je ne peux pas afficher directement chn ici.
	  Par contre, je pourrais écrire chn dans un fichier, par exemple.
	  Ici, je vais juste l'afficher en binaire pour bien vérifier les valeurs.*/

	printf("conversion_utf8(0x%06X) (%7d): ", codePoint, codePoint);
	write(1, chn, strlen(chn));
	write(1, " <= write\n", 10);
	for(i=0 ; chn[i]!='\0' ; i++)
	{
		unsigned char ch = (unsigned char)chn[i];
		if(i != 0) { putchar(' '); }
		printf("%s%s", bin4[(ch >> 4) & 0x0F], bin4[ch & 0x0F]);
	}
	putchar('\n');
}

void TestConversion(void)
{
	int i;
	for(i=0 ; i<10 ; i++)
	{
		printf("Nombre de bits de %2d: %d\n", i, numberbits(i));
	}
	TestUtf8('a');
	TestUtf8(L'é');
	TestUtf8(L'∑');
	TestUtf8(232);
	TestUtf8(0x0000A0); /*Quelques valeurs exemple*/
	TestUtf8(0x002554);
	TestUtf8(0x00FEFF); /*La fameuse BOM*/
	TestUtf8(0x00FFFF);
	TestUtf8(0x010000);
	TestUtf8(0x10000 * 17 - 1);
	/*Cette valeur est illégale en Unicode (car elle ne peut pas être encodée en UTF-16),
	  mais reste acceptée par la fonction car elle ne dépasse pas 21 bits.*/
	TestUtf8(0x1FFFFF);
	/*Cette valeur-ci dépasse la capacité de la fonction et est donc refusée.*/
	TestUtf8(0x200000);
}

int main()
{
	TestConversion();
	return 0;
}
