<?php
echo "<table border='1' cellspacing='0' cellpadding='10'>";

$num = 1;
for ($row = 1; $row <= 8; $row++) {
    echo "<tr>";
    for ($col = 1; $col <= 8; $col++) {
        $color = ($row + $col) % 2 == 0 ? "white" : "black";
        echo "<td style='background:$color; color:red;'>$num</td>";
        $num++;
    }
    echo "</tr>";
}
echo "</table>";
?>
