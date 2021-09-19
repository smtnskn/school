## H1 - CTF walkthrough, Kali Live USB

http://terokarvinen.com/2019/penetration-testing-tunkeutumistestaus-ict4tn027-3004-intensive-summer-course-2019-w21w22-5-credits

#### Tehtävänanto:

1. [CTF walktrough. Katso verkosta (esim Youtubesta) jonkin capture the flag -kilpailun ratkaisu. Mitä uusia työkaluja opit? Kokeile jotain mainittua työkalua (tarvittaessa koneella, joka ei ole kiinni Internetissä).](#tehtava1)

2. [Kali Live USB. Tee Kali Live USB -tikku. Kokeile, että se käynnistyy. Vinkki: käytä USB3-tikkua ja dd:tä. Ole tarkkana, mitä laitat of= kohtaan, ettet kirjoita kovalevysi päälle.](#tehtava2)

---

**Molemmat tehtävät ovat Kalin osioimista lukuunottamatta tehty MacOS:llä.**

#### <a id="tehtava1">1. Työkaluja CTF walkthroughsta</a>

Vilkaisin [securitybytes.io](https://securitybytes.io):sta nimim. [Leigh ratkaisun vulnhub.comin Necromancer 1 CTF:ään.](https://securitybytes.io/vulnhub-com-necromancer-1-ctf-walkthrough-4b58a708f747?gi=8abf7af97ae5)

Leigh käyttää monia, monia eri työkaluja, mm. `nmap`, `nc`, `arp-scan`, `nikto`, `binwalk`, `snmpwalk`, `aircrack-ng`, `hydra`...\
Kokeilin kolmea ensimmäistä kotiverkossani.

Aloitin `arp-scan`illa, `arp-scan -l`:\
![arp-scan-utun-1](/tunkeutumistestaus-2019/h1-ctf-kali/screenshots/arp-scan-utun-1.png)

Hmm, en tietääkseni käytä tunnelointia mihinkään tällä koneella. Pikaisella [ankkaamisella](https://duck.com) selvisi, että kyseessä on Back To My Mac -toiminnon luoma vekotin, jota en käytä. Päätin laittaa sen pois päältä. Ankka myös kertoi, että tuota toimintoa hallinnoi `/System/Library/LaunchDaemons/com.apple.awacsd.plist`-tiedosto. Olen poistanut `.plist`-tiedostoja käytöstä aiemminkin, joten tiesin, mitä tehdä:\
![arp-scan-utun-2](/tunkeutumistestaus-2019/h1-ctf-kali/screenshots/arp-scan-utun-2.png)

Laitoin myös laitteen pois päältä komennolla `sudo ifconfig utun0 down`.

Uusi yritys:\
![arp-scan](/tunkeutumistestaus-2019/h1-ctf-kali/screenshots/arp-scan.png)

Windows-boksi ja Hyper-V:n päällä pyörivä Arch Linux-virtuaalikone löytyivät.

Seuraavaksi `netcat`, eli `nc`. Portilla `47066` kuuntelee `Wireguard`, katsotaan mitä `nc` sanoo:\
![nc-1](/tunkeutumistestaus-2019/h1-ctf-kali/screenshots/nc-1.png)

Entäs portti `53`, jolla kuuntelee `dnscrypt-proxy`:\
![nc-2](/tunkeutumistestaus-2019/h1-ctf-kali/screenshots/nc-2.png)

Entäs RDP-palvelin:\
![nc-3](/tunkeutumistestaus-2019/h1-ctf-kali/screenshots/nc-3.png)

Viimeiseksi kokeilin `nmap`ia optioilla `-sSU` (tcp+udp), `-p-` (portit 1-65535) ja `-T4` (nopea ajo).\
Yritin aluksi ajaa komentoa MacOS:stä käsin, mutta se toimi aivan järjettömän hitaasti. Luovutin 15 minuutin odottelun jälkeen ja suoritin komennon Windows-boksin sisällä pyörivästä Arch Linux-virtuaalikoneesta käsin, jolla komento suoriutui huomattavasti nopeammin.

Ensimmäisenä kohteena Windows-isäntäkone, toisena MacBook:\
![nmap](/tunkeutumistestaus-2019/h1-ctf-kali/screenshots/nmap.png)

---

#### <a id="tehtava2">2. Kali Live USB</a>

Olin tehnyt Kali Live USB-tikun jo aiemmin, mutta päätin tehdä uuden ja ottaa käyttöön pysyvän (persistent) osion.

Alkuun tarkistin `diskutil list` -komennolla, mikä laite tikku on. Vastaus: `/dev/disk2`.\
Otin tikun pois käytöstä komennolla `diskutil unmount /dev/disk2` ja laitoin Kalin tikulle `dd`llä (HUOM: Jos käytät GNU:n `dd`-ohjelmaa, täytyy `bs`-optiossa käyttää isoa kirjainta, eli `bs=1M`):\
![dd-kali](/tunkeutumistestaus-2019/h1-ctf-kali/screenshots/dd-kali.png)

Boottasin tikulta ja kun pääsin komentokehotteeseen, tarkistin komennolla `fdisk -l`, mikä laite on USB-tikku, omassa tapauksessani se oli `/dev/sdb`.

Käynnistin `parted`in komennolla `parted /dev/sdb` ja tarkistin mistä vapaa tila tikulla alkaa ja minne se päättyy komennolla `print free`.\
Edelleen `parted`in sisällä, loin uuden osion komennolla `mkpart primary [aloitus] [lopetus]`.\
(korvaa `[aloitus]` ja `[lopetus]` `print free`stä saamillasi luvuilla, itselläni `3848MB` ja `15.5GB`)

`parted`ista poistuttuani tarkistin uuden osion laitteen komennolla `fdisk -l`, joka oli `/dev/sdb3`.\
Jatkoin luomalla uudelle osiolle `ext4`-tiedostojärjestelmän, `mkfs.ext4 -L persistence /dev/sdb3`.

Viimeiseksi otin pysyvän osion käyttöön seuraavasti:\
`> mkdir -p /mnt/kali-usb && mount /dev/sdb3 /mnt/kali-usb`\
`> echo "/ union" > /mnt/kali-usb/persistence.conf && umount /dev/sdb3`

Käynnistin koneen uudelleen ja nyt Kalin pystyi käynnistämään boottivalikosta `Live USB Persistence` -valinnalla.
