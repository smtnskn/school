<?php

include ('functions.php');

if (!empty($_REQUEST['note'])) {
    $id		= $_REQUEST['id']; 
    $date	= $_REQUEST['date'];
    $time	= $_REQUEST['time'];
    $note	= $_REQUEST['note'];

    $db = new PDO('sqlite:db/test.db');

    delete($db, $id);
    insert($db, $date, $time, $note);

    echo ($db -> lastInsertId());

    $db = null;
}

?>
