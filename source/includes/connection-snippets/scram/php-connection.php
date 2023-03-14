<?php
use MongoDB\Client;
use MongoDB\Driver\ServerApi;

// Replace the placeholder with your Atlas connection string
$uri = '<connection string>';

// Specify Stable API version 1
$serverApi = new ServerApi(ServerApi::V1);

// Create a new client and connect to the server
$client = new Client($uri, [], ['serverApi' => $serverApi]);

try {
    // Send a ping to confirm a successful connection
    $database = $client->admin;
    $cursor = $database->command(['ping' => 1]);
    echo "Pinged your deployment. You successfully connected to MongoDB!\n";
} catch (Exception $e) {
    echo $e->getMessage();
}
?>