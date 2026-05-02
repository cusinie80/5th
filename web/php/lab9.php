<?php
$conn = new mysqli("localhost", "root", "", "labassignment1");
$conn->query("DELETE FROM student WHERE address='Lalitpur'");
echo "Records deleted";
?>
