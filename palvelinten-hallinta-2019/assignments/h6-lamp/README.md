## H6 - LAMP

http://terokarvinen.com/2018/aikataulu-palvelinten-hallinta-ict4tn022-3003-ti-ja-3001-to-loppukevat-2019

#### Tehtävänanto:

1. [Asenna LAMP Saltilla.](#tehtava1)

#### Ympäristö:

Minion: Hyper-V -virtuaalikoneella pyörivä Ubuntu 18.04.2 LTS x64, isäntänä Windows Embedded 8.1 Industry Pro x64 nimettömällä pöytäkoneella:\
![neofetch-minion](/palvelinten-hallinta-2019/assignments/h6-lamp/screenshots/neofetch-minion.png)

Master: pilvipalvelimella pyörivä Parabola GNU/Linux-libre x64:
![neofetch-master](/palvelinten-hallinta-2019/assignments/h6-lamp/screenshots/neofetch-master.png)

---

### <a id="tehtava1">1. LAMP -asennus</a>

Aloitin luomalla herra-orja arkkitehtuurin aiemmissa tehtävissä kuvatulla tavalla.\
Kun koneet juttelivat toisilleen, loin hakemiston `/srv/salt/lamp` ja sinne tilan `init.sls`.

Linux oli jo käytössä, joten aloitin Apachen ja sen PHP-lisäosan asennuksella:\
![sls-1](/palvelinten-hallinta-2019/assignments/h6-lamp/screenshots/sls-1.png)\
![apache-php-installed-1](/palvelinten-hallinta-2019/assignments/h6-lamp/screenshots/apache-php-1.png)\
![apache-php-installed-2](/palvelinten-hallinta-2019/assignments/h6-lamp/screenshots/apache-php-2.png)

Onnistui.\
Jatkoin luomalla `index.php`-tiedoston ja lisäsin sen käyttöönoton tilaan:\
![index-php](/palvelinten-hallinta-2019/assignments/h6-lamp/screenshots/index-php.png)\
![sls-2](/palvelinten-hallinta-2019/assignments/h6-lamp/screenshots/sls-2.png)

Ajoin tilan:\
![index-php-applied](/palvelinten-hallinta-2019/assignments/h6-lamp/screenshots/index-php-applied.png)

Ja kokeilin selaimella:\
![index-php-browser](/palvelinten-hallinta-2019/assignments/h6-lamp/screenshots/index-php-browser.png)

Toimi.\
Seuraavaksi MariaDB. Lisäsin sen asennuksen tilaan:\
![sls-3](/palvelinten-hallinta-2019/assignments/h6-lamp/screenshots/sls-3.png)

Ajoin tilan:\
![mariadb-1](/palvelinten-hallinta-2019/assignments/h6-lamp/screenshots/mariadb-1.png)
![mariadb-2](/palvelinten-hallinta-2019/assignments/h6-lamp/screenshots/mariadb-2.png)

Tosiaan, clientillä ja serverillä ei ole omaa serviceä. Muutin tilaa:\
![sls-mariadb](/palvelinten-hallinta-2019/assignments/h6-lamp/screenshots/sls-mariadb.png)

Uusi yritys:\
![mariadb-3](/palvelinten-hallinta-2019/assignments/h6-lamp/screenshots/mariadb-3.png)

Onnistui.\
Kokeilin ajaa komentoja:\
![mariadb-queries](/palvelinten-hallinta-2019/assignments/h6-lamp/screenshots/mariadb-queries.png)
