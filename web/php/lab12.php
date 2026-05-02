<?php
setcookie("user", "AyushSR", time() + 3600);
if (isset($_COOKIE["user"])) {
    echo "Cookie Value: " . $_COOKIE["user"];
}
?>
<?php
session_start();
$_SESSION["username"] = "Ayush";
echo "Session Value: " . $_SESSION["username"];
?>
