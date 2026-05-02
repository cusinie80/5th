<?php
$numArr = [10, 20, 30, 40, 50];
echo 'Before: '; print_r($numArr);
echo '<br>';
$numArr[2] = 99;
echo 'After:  '; print_r($numArr);
echo '<br>';
$assocArr = ['name' => 'Suresh', 'age' => 20, 'city' => 'Kathmandu'];
echo 'Before: '; print_r($assocArr);
echo '<br>';
$assocArr['city'] = 'Pokhara';
echo 'After:  '; print_r($assocArr);
echo '<br>';
$multiArr = [
    ['name' => 'Ram',   'marks' => 80],
    ['name' => 'Shyam', 'marks' => 75],
];
echo 'Before: '; print_r($multiArr);
echo '<br>';
$multiArr[1]['marks'] = 90;
echo 'After:  '; print_r($multiArr);
echo '<br>';
?>
