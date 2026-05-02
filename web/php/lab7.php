
<?php
$conn = mysqli_connect('localhost', 'root', '', 'labassignment1');
if (!$conn) { die('Connection failed: ' . mysqli_connect_error()); }

$result = mysqli_query($conn, 'SELECT * FROM student');

echo '<table border="1" cellpadding="8">';
echo '<tr><th>Roll</th><th>Name</th><th>Address</th><th>Contact</th></tr>';

while ($row = mysqli_fetch_assoc($result)) {
    echo '<tr>';
    echo '<td>' . $row['roll']    . '</td>';
    echo '<td>' . $row['name']    . '</td>';
    echo '<td>' . $row['address'] . '</td>';
    echo '<td>' . $row['contact'] . '</td>';
    echo '</tr>';
}
echo '</table>';
mysqli_close($conn);
?>
