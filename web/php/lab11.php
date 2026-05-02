<?php
$name = "";
$error = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (empty($_POST["name"])) {
        $error = "Name is required";
    } else {
        $name = $_POST["name"];
    }
}
?>

<form method="post">
    Name: <input type="text" name="name">
    <span style="color:red;"><?php echo $error; ?></span>
    <input type="submit">
</form>
