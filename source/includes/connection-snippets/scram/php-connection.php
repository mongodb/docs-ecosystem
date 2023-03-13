<?php

require_once __DIR__ . '/vendor/autoload.php';
use MongoDB\Client;
use MongoDB\Driver\ServerApi;

$serverApi = new ServerApi(ServerApi::V1);
$client = new Client('<connection string>', [], ['serverApi' => $serverApi]);

try {
    $database = $client->admin;
    $cursor = $database->command(['ping' => 1]);
    echo "Pinged your deployment. You successfully connected to MongoDB!\n";
} catch (Exception $e) {
    echo $e->getMessage();
}
?>