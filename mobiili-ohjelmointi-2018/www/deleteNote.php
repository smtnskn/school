<?php

include ('functions.php');

if (!empty($_REQUEST['id'])) {
    $id = $_REQUEST['id'];
    
    $db = new PDO('sqlite:db/test.db');

    delete($db, $id);

    $db = null;
}

?>
