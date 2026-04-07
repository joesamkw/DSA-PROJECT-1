<?php

$username = escapeshellarg($_POST['username']);
$password = escapeshellarg($_POST['password']);
$command = "./register $username $password";
$output = shell_exec($command);



echo "<h2>$output</h2>";
echo "<a href='index.html'>Go to Login</a>";

?>