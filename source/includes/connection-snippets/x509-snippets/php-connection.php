<?php
/* Begin x509 connection */
$certificateKeyFilePath = '/etc/certs/mongodb/client.pem';
$client = new MongoDB\Client(
    'mongodb+srv://<cluster-url>/test?authSource=$external&tlsCertificateKeyFile=' . $certificateKeyFilePath . '&retryWrites=true&w=majority&authMechanism=MONGODB-X509'
);
$collection = $client->testDB->testCol;
$docCount = $collection->count([]);
print($docCount);
/* End x509 connection */