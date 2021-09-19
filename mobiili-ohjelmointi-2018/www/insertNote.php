<?php

include ('functions.php');

if (!empty($_REQUEST['note'])) {
    $date = $_REQUEST['date'];
    $time = $_REQUEST['time'];
    $note = $_REQUEST['note'];

    $db = new PDO('sqlite:db/test.db');

    insert($db, $date, $time, $note);

    echo ($db -> lastInsertId());

    $db = null;
}

?>
