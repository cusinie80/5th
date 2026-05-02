<?php
$conn = mysqli_connect('localhost', 'root', '');
if (!$conn) {
    die('Connection failed: ' . mysqli_connect_error());
}
$sql = 'CREATE DATABASE IF NOT EXISTS labassignment1';
if (mysqli_query($conn, $sql)) {
    echo 'Database labassignment1 created successfully.';
} else {
    echo 'Error: ' . mysqli_error($conn);
}
mysqli_close($conn);
?>
