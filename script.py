#!/usr/bin/python3.2
#-*- coding: utf-8 -*-

import smtplib
from email.MIMEMultipart import MIMEMultipart
from email.MIMEText import MIMEText
from getpass import getpass

print ("send check mail pole emploi ?")
while 1:
	try:
		ans = raw_input("y/n : ")
		if ans == "n":
			exit()
		elif ans == "y":
			fromaddr = "julien.debladis@gmail.com"
			toaddr = "julien.debladis@gmail.com"
			msg = MIMEMultipart()
			msg['From'] = fromaddr
			msg['to'] = toaddr
			msg['subject'] = "<test>"
			body = "Bonjour,\n\nPourrais-je avoir un recap de mes heures effectuees pour le pole emploi.\n\nMerci"
			msg.attach(MIMEText(body, 'plain'))
			mail = smtplib.SMTP('smtp.gmail.com', 587)
			mail.starttls()
			while 1:
				try:
					mdp = getpass()
					mail.login(fromaddr, mdp)
					text = msg.as_string()
					mail.sendmail(fromaddr, toaddr, text)
					exit()
				except KeyboardInterrupt:
					print "\nkthxbye"
					exit()
				except EOFError:
					print "\nkthxbye"
					exit()
				except smtplib.SMTPAuthenticationError:
					print ("\x1B[31mWrong password\x1B[00m")
	except KeyboardInterrupt:
		print "\nkthxbye"
		exit()
	except EOFError:
		print "\nkthxbye"
		exit()
