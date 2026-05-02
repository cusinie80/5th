<form method="post" action="">
    Name: <input type="text" name="name">
    <input type="submit">
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = $_POST["name"];
    echo "POST Name: " . $name;
}

if (isset($_GET["name"])) {
    echo "GET Name: " . $_GET["name"];
}
?>
