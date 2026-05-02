<?php
$conn = mysqli_connect('localhost', 'root', '', 'labassignment1');
if (!$conn) { die('Connection failed: ' . mysqli_connect_error()); }

$sql = 'CREATE TABLE IF NOT EXISTS student (
    roll    INT AUTO_INCREMENT PRIMARY KEY,
    name    VARCHAR(50),
    address VARCHAR(100),
    contact VARCHAR(15)
)';
mysqli_query($conn, $sql);
echo 'Table created successfully.<br>';
$sql1 = "INSERT INTO student (name, address, contact)
         VALUES ('Suresh', 'Dallu', '9800000001'),
        ('Sandeep','Lalitpur','9800000002') ";
mysqli_query($conn, $sql1);
echo 'Record inserted.<br>';
mysqli_close($conn);
?>
