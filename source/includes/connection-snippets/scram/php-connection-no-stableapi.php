<?php
use MongoDB\Client;

// Replace the placeholder with your Atlas connection string
$uri = '<connection string>';
// Create a new client and connect to the server
$client = new Client($uri);

try {
    // Send a ping to confirm a successful connection
    $database = $client->admin;
    $cursor = $database->command(['ping' => 1]);
    echo "Pinged your deployment. You successfully connected to MongoDB!\n";
} catch (Exception $e) {
    echo $e->getMessage();
}
?>