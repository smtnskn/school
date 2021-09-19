## H4 - HackTheBox

http://terokarvinen.com/2019/penetration-testing-tunkeutumistestaus-ict4tn027-3004-intensive-summer-course-2019-w21w22-5-credits

#### Tehtävänanto:

1. [Hedelmiä matalalla. Mitkä vaikuttavat HackTheBoxin helpoimmilta kohteilta? Tiedustele HackTheBox-verkko esimerkiksi porttiskannerilla ja ryömijällä. Noudata Rules-kohdassa annettua scopea.](#tehtava1)

2. [Bonus: murtaudu jollekin HackTheBoxin maalikoneelle. Voit katsoa weppiliittymästä vinkkiä siitä, mitkä koneet ovat helppoja.](#tehtava2)

---

#### Aloitus: Kali + QEMU

En halunnut bootata konettani tikulta, joten kokeilin huvikseni [QEMU:a](https://www.qemu.org).

Ensimmäinen yritys, jossa käynnistän Kalin USB-tikulta virtuaalikoneeseen:\
![kali-qemu-1](/tunkeutumistestaus-2019/h4-hackthebox/screenshots/kali-qemu-1.png)

![kali-qemu-2](/tunkeutumistestaus-2019/h4-hackthebox/screenshots/kali-qemu-2.png)

![metasploit](/tunkeutumistestaus-2019/h4-hackthebox/screenshots/metasploit.png)

Helei, näytti toimivan heittämällä.\
Ilo ei valitettavasti kestänyt kauaa, sillä virtuaalikone kaatui. Kyseessä on ilmeisesti [tunnettu bugi MacOS:ää käyttäessä](https://bugs.launchpad.net/qemu/+bug/1818937). Sain Kalin ja QEMUn toimimaan yhdessä pitkällisen säätämisen jälkeen seuraavilla optioilla:\
![qemu-shortcuts](/tunkeutumistestaus-2019/h4-hackthebox/screenshots/qemu-shortcuts.png)

`qemu-live-x86()` käynnistää Kalin USB-tikulta, `qemu-disk-x86()` käynnistää virtuaalikoneen käyttäen qcow2-levykuvaa, jolle Kali on asennetty, ja `qemu-install-x86()` käynnistää Kalin USB-tikulta ja avaa myös qcow2-levykuvan, jolle Kalin voi sitten asentaa. Levykuvan täytyy olla riittävän iso - päivityksien jälkeen Kali-asennus vei n. 13GB kovalevytilaa.

---

#### <a id="tehtava1">1. [HackTheBox](https://www.hackthebox.eu) kohteita</a>

Käynnistin `metasploit`in ja aloitin verkon kartoittamisen komennolla `db_nmap -n -v -sn 10.10.10.0/24`:\
![nmap-scan-1](/tunkeutumistestaus-2019/h4-hackthebox/screenshots/nmap-scan-1.png)

Tulostin löydetyt palvelimet komennolla `hosts --up -c address` ja tallensin tulokset tiedostoon `/root/hackthebox/hostsup`. Jatkoin verkon tutkimista komennolla `db_nmap -n -Pn -sC -sV -O -iL /root/hackthebox/hostsup`.

Kun tuloksia oli tullut, laitoin taustalle hitaampia `nmap` komentoja ja aloin tutkimaan mitä oli löytynyt:\
![ftp](/tunkeutumistestaus-2019/h4-hackthebox/screenshots/ftp.png)

![http](/tunkeutumistestaus-2019/h4-hackthebox/screenshots/http.png)

![ssh](/tunkeutumistestaus-2019/h4-hackthebox/screenshots/ssh.png)

![imap](/tunkeutumistestaus-2019/h4-hackthebox/screenshots/imap.png)

`eyewitness`illä sain kuvia siitä, mitä avoimilla http-palvelimilla on vastassa:\
![eyewitness-report](/tunkeutumistestaus-2019/h4-hackthebox/screenshots/eyewitness-report.png)

Veikkaan, että joukosta löytyy helppoja kohteita sekä HTTP:n, FTP:n, että SSH:n takaa.

---

#### <a id="tehtava2">2. HackTheBox murtautuminen</a>

Lähdin tutkimaan erästä `nmap`in löytämää FTP-palvelinta. Onnisti välittömästi:\
![ftp-user-txt](/tunkeutumistestaus-2019/h4-hackthebox/screenshots/ftp-user-txt.png)

![user-flag](/tunkeutumistestaus-2019/h4-hackthebox/screenshots/user-flag.png)
