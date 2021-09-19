## H2 - WebGoat -tehtävä, MITRE Att&ck -tekniikka

http://terokarvinen.com/2019/penetration-testing-tunkeutumistestaus-ict4tn027-3004-intensive-summer-course-2019-w21w22-5-credits

#### Tehtävänanto:

1. [Ratkaise jokin WebGoatin tehtävä. Hyödynsitkö jotain OWASP10 -haavoittuvuutta? Mitä niistä?](#tehtava1)

2. [Mainitse esimerkki MITRE:n Att&ck tekniikasta, joka soveltuu weppiin. Osaatko antaa esimerkin hyökkäyksestä tai haittaohjelmasta, jossa sitä on käytetty?](#tehtava2)

---

#### <a id="tehtava1">1. WebGoat, Silent Transactions Attack</a>

Jatkoin siitä kohdasta mihin luennolla tänään jäin, eli AJAX Security - Silent Transactions Attack:\
![silent-transactions-attack](/tunkeutumistestaus-2019/h2-webgoat-mitre/screenshots/silent-transactions-attack.png)

Tehtävänä oli siis vaivihkaa suorittaa tilisiirto.

Aiempien AJAX Security -tehtävien perusteella ajattelin, että DOM:ia manipuloimalla voisi ehkä tämänkin suorittaa. Avasin siis Firefoxilla sivun lähdekoodin (right click -> View Page Source), mutta sieltä ei löytynyt mitään mielenkiintoista:\
![page-source](/tunkeutumistestaus-2019/h2-webgoat-mitre/screenshots/page-source.png)

Seuraavaksi kokeilin valita hiirellä tehtäväalueen sivulta ja View Page Sourcen sijasta klikkasin View Selection Source. Koodi oli sotkuista, joten ajoin sen ![htmlformatter.com](https://www.htmlformatter.com):in läpi, jotta se olisi helpompi lukea:\
![selection-source-js](/tunkeutumistestaus-2019/h2-webgoat-mitre/screenshots/selection-source-js.png)

Ainoa asia mikä tässä iski silmääni, oli tuo mystinen `silentTransaction.js`-tiedosto. Avasin sen:\
![js-source](/tunkeutumistestaus-2019/h2-webgoat-mitre/screenshots/js-source.png)

`processData` ja `callback` -funktioissa ei ole mitään mielenkiintoista, mutta `submitData` sen sijaan ottaa argumentteja.\
Avasin Firefoxin kehitystyökaluista konsolin ja huomasin, että siinä on autofill-ominaisuus, joka kiltisti täydentää komentoja:\
![autofill](/tunkeutumistestaus-2019/h2-webgoat-mitre/screenshots/autofill.png)

How nice. Tällähän voisi siis sokkona lähteä kokeilemaan mitä tuhoa on mahdollista saada aikaan.

Suoritan funktion antamalla `accountNo`-argumentiksi `1337` ja `balance`-argumentiksi `31337`:\
![js-function](/tunkeutumistestaus-2019/h2-webgoat-mitre/screenshots/js-function.png)

Tehtävä purkissa:\
![success](/tunkeutumistestaus-2019/h2-webgoat-mitre/screenshots/success.png)

OWASP 10 -haavoittuvuuksista väittäisin tässä tulleen esille `A1:2017-Injection`, `A5:2017-Broken Access Control`, sekä `A6:2017-Security Misconfiguration`.\
Itse hyökkäys oli selkeä injektio, sillä syötin suoraan JS-funktiolle omat argumenttini. Injektio itse oli mahdollinen, koska sivua ei ollut turvallisesti koodattu ja näin käyttäjä pääsi ajamaan JS-koodia omin nokkineen konsolista.

---

#### <a id="tehtava2">2. MITRE Att&ck</a>

[Network Sniffing](https://attack.mitre.org/techniques/T1040/) on perustavanlaatuinen tekniikka, jolla vakoillaan ja mahdollisesti tallennetaan ja analysoidaan verkossa liikkuvaa tietoa. Linkittämälläni sivulla mainitaan mm. Lateral Movement ja Defense Evasion mahdollisina seuraavina askelina. Verkon nuuskimista voi toki käyttää myös hyödyllisiin tarkoituksiin, kuten oman verkon auditointiin.

Mahdollisia työkaluja ovat Wireshark, dnsiff, [Meterpreter](https://www.offensive-security.com/metasploit-unleashed/packet-sniffing/) ja Driftnet.

Esimerkki haittaohjelmasta joka hyödyntää nuuskintaa on [EMOTET](https://blog.trendmicro.com/trendlabs-security-intelligence/new-banking-malware-uses-network-sniffing-for-data-theft/).
