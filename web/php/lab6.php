<?php
$conn = new mysqli("localhost", "root", "", "labassignment1");

for ($i = 1; $i <= 10; $i++) {
    $conn->query("INSERT INTO student (name, address, contact) 
    VALUES ('Student$i', 'Address$i', '98000000$i')");
}

echo "10 records inserted";
?>
