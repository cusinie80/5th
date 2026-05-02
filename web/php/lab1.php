<?php
echo "<table border='1'><tr>";

for ($i = 1; $i <= 10; $i++) {
    if ($i % 2 == 0) {
        echo "<td style='background-color: blue; width:50px; height:50px;'></td>";
    } else {
        echo "<td style='background-color: green; width:50px; height:50px;'></td>";
    }
}

echo "</tr></table>";
?>
