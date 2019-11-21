<?php
/* Begin x509 connection */
$subject = "mongodb+srv://<your_subject>"; 
$manager = new MongoDB\Driver\Manager(
    $subject + "@<cluster-url>/?ssl=true&authMechanism=MONGODB-X509",
  [],
  [
    "pem_file" => "/etc/certs/mongodb/v3/client.pem",
    "ca_file" => "/etc/certs/mongodb/v3/ca.pem",
  ]
);
/* End x509 connection */