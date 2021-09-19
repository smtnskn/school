## H5 - Konferenssivideo, Metasploitable, HackTheBox

http://terokarvinen.com/2019/penetration-testing-tunkeutumistestaus-ict4tn027-3004-intensive-summer-course-2019-w21w22-5-credits

#### Tehtävänanto:

1. [Konfferenssi kotona. Katso jokin esitys pentest-aiheisesta konfferenssista ja kommentoi sen parhaita paloja. Esim. Disoebey, RSA, BlackHat…](#tehtava1)

2. [Metasploitable. Korkkaa jokin uusi palvelu Metasploitablesta (jokin muu kuin vsftpd). Voit käyttää Metasploitable 2 tai 3.](#tehtava2)

3. [HackTheBox, korkkaa jokin kone.](#tehtava3)

---

#### <a id="tehtava1">1. Konferenssivideo </a>

Katsoin 35C3 -konferenssissa pidetyn Sneaking In Network Security -esitelmän. Alla linkkejä, joista sen voi katsoa:

https://media.ccc.de/v/35c3-9603-sneaking_in_network_security \
https://fi.invidious.snopyta.org/watch?v=D5qTZm2NRlI \
https://www.youtube.com/watch?v=D5qTZm2NRlI

Esitelmä on tunnin mittainen, eikä se käsittele ainoastaan turvallisuuteen liittyviä asioita, mutta alla muistiinpanoni tälle kurssille relevanteista seikoista.

Yleistä turvallisuuteen liittyvää:

- Verkot tuppaavat olemaan puutteellisesti segmentoituja - reunapalvelimet ovat usein turvattu, mutta ne ohitettuaan tunkeilijoilla ei ole vastassaan suurempia ongelmia liikkua sisäverkossa

![google](/tunkeutumistestaus-2019/h5-conference-htb/screenshots/google.jpg)

- Sinisen tiimin kuuluu olla yhtä huomaamaton kuin punaisen (ei häiritä verkon toimintaa, pysytään poissa käyttäjien tieltä)
- Turvallisuutta ei pidä rakentaa kehitysympäristön ympärille, vaan se on sisällytettävä kehitysprosessiin itseensä
- "Secure by default" + epäturvallisten konfiguraatioiden toteuttamisen pitäisi olla vaikeaa
- Turvallisuusjärjestelyiden pitää toimia verkon järjestelyistä riippumatta

Airbnb:n ratkaisusta:

![airbnb-1](/tunkeutumistestaus-2019/h5-conference-htb/screenshots/airbnb-1.png)

- Molemminpuolinen TLS-identifikaatio verkon sisällä + service discovery
- Palvelut saatavilla vain ja ainoastaan proxyjen kautta
- Verkko on segmentoitu palveluiden mukaan, ei aliverkkojen
	- "Allow the payment config page to call the payment backend service - but don't allow the Slack bot to!"

  ![airbnb-2](/tunkeutumistestaus-2019/h5-conference-htb/screenshots/airbnb-2.png)

  ![airbnb-3](/tunkeutumistestaus-2019/h5-conference-htb/screenshots/airbnb-3.png)

Käytettyjä teknologioita:

- SmartStack service discovery
- Envoy Proxy
- HAProxy

---

#### <a id="tehtava2">2. Metasploitable</a>

...

---

#### <a id="tehtava3">3. HTB</a>

...
