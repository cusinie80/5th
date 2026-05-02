<?php
$conn = new mysqli("localhost", "root", "", "labassignment1");
$conn->query("UPDATE student SET address='Dallu' WHERE name='Suresh'");
echo "Record updated";
?>
