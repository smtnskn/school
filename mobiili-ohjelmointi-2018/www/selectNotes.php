<?php
try {
    $db		= new PDO('sqlite:db/test.db');
    $sql	= "SELECT * FROM notes ORDER BY note_id DESC";
    $array 	= $db -> query($sql) -> fetchAll(PDO::FETCH_ASSOC);

    echo json_encode($array);
} catch (PDOException $e) {
    echo("Database error: " . $e);
}

$db = null;

?>

