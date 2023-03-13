<?php

require_once __DIR__ . '/vendor/autoload.php';
use MongoDB\Client;

$client = new Client('<connection string>');

try {
    $database = $client->admin;
    $cursor = $database->command(['ping' => 1]);
    echo "Pinged your deployment. You successfully connected to MongoDB!\n";
} catch (Exception $e) {
    echo $e->getMessage();
}
?>