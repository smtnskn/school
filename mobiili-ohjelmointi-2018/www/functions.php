<?php

function delete($db, $id) {
    $db -> exec(
        "DELETE FROM notes WHERE note_id = '$id';"
    ); 
}

function insert($db, $date, $time, $note) {
    $db -> exec(
        "INSERT INTO notes(date, time, note) VALUES('$date', '$time', '$note');"
    );
}

?>
