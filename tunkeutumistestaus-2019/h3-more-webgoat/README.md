## H3 - WebGoat

http://terokarvinen.com/2019/penetration-testing-tunkeutumistestaus-ict4tn027-3004-intensive-summer-course-2019-w21w22-5-credits

#### Tehtävänanto:

1. [Tee WebGoatista jokin tehtävä.](#tehtava1)

---

#### <a id="tehtava1">1. WebGoat, Off-by-One Overflow</a>

Tässä tehtävässä näyttää olevan jokin vialla, joten en tiedä, suoritinko tämän kunnialla vai en. Ongelma ilmenee tehtävän edetessä.

Tarkoitus on siis selvittää buffer overflown avulla, missä huoneessa hotellin VIP-asiakas asustaa. Aloitin täyttämällä kentät normaalisti ja seuraamalla mitä tapahtuu.\
![off-by-one](/tunkeutumistestaus-2019/h3-more-webgoat/screenshots/off-by-one.png)

Ensimmäisen sivun lähdekoodissa ei näkynyt mitään mielenkiintoista. Annoin etunimeksi "John", sukunimeksi "Smith" ja huoneen numeroksi "888".

Toisen sivun lähdekoodissa oli piilotettuja kenttiä, mutta en tiennyt, mitä niillä kuuluisi tehdä:\
![2nd-page](/tunkeutumistestaus-2019/h3-more-webgoat/screenshots/2nd-page.png)\
![hidden-values](/tunkeutumistestaus-2019/h3-more-webgoat/screenshots/hidden-values.png)

Painoin "Accept Terms".\
Ja nyt kävi oudosti, sillä WebGoatin mukaan olen läpäissyt tehtävän:\
![success](/tunkeutumistestaus-2019/h3-more-webgoat/screenshots/success.png)

Lähdekoodissa ei ollut huomioitavaa. Oliko huoneen 888 John Smith sattumalta VIP-vieras? Ei kai sentään. Painoin "Restart Lesson" ja jatkoin kokeilemista.

En tunne JavaScriptiä juuri ollenkaan, mutta tiedän mitä buffer overflowt ovat. Kokeilin siis mitä tapahtuu, jos syötän lomakkeisiin hillittömän määrän tekstiä.\
Kirjoitin konsolissa funktion, joka generoi 5000 merkin pituisen merkkijonon ja kopioin sen lomakkeisiin:\
![function](/tunkeutumistestaus-2019/h3-more-webgoat/screenshots/function.png)

Painoin "Submit", mutta toisella sivulla, eikä sen lähdekoodissa näkynyt mitään erikoista. Lomakkeet olivat kiltisti hyväksyneet 5000-merkkisen stringin:\
![string](/tunkeutumistestaus-2019/h3-more-webgoat/screenshots/string.png)

Hmm. Tuskin tässä tuota pidempää merkkijonoa sentään kuuluu käyttää. Yritin etsiä hakukoneesta tietoa JS buffer overflow exploiteista, mutta en löytänyt mitään.

Sorruin käyttämään "Show Hints" toimintoa, jossa sanotaan seuraavasti: `"Typically, web-based buffer overflows occur just above the value of 2 to the power of a number. E.g. 1024 + 1, 2048 + 1, 4096 + 1"`.\
Ok, kokeilin samaa 1025, 2049, sekä 4097 merkillä, mutta lopputulos oli sama, eli toisella sivulla, tai sen lähdekoodissa, ei ollut mitään huomioitavaa.

Aloitin taas alusta 5000 merkillä, mutta tällä kertaa en pysähtynyt toiselle sivulle, vaan jatkoin kolmannelle asti ja kas kummaa:\
![overflow](/tunkeutumistestaus-2019/h3-more-webgoat/screenshots/overflow.png)

OK! Kokeilin "Johnathan", "Ravern", "4321" ja WebGoat sanoi taas "Congratulations."\
Resetoin tehtävän ja kokeilin "Lewis", "Hamilton", "9901" ja taas sain onnittelut.\
Tämä tehtävä siis näyttää päästävän läpi, jos vain laittaa lomakkeisiin minkä tahansa listalla olevan nimen?

Löysin kyllä salaisia tietoja, mutta tämän bugin takia en tiedä onko tämä onnistuneesti suoritettu vai ei.
