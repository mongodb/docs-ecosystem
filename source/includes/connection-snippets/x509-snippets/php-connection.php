<!-- Begin x509 connection -->
<?php

$database = 'test';
$subject = "mongodb://<your_subject>"; // mongodb://CN=<host>,OU=TestClientCertificateOrgUnit,O=TestClientCertificateOrg,L=TestClientCertificateLocality,ST=TestClientCertificateState,C=US
$manager = new MongoDB\Driver\Manager(
  $subject + "@localhost/?ssl=true&authMechanism=MONGODB-X509",
  [],
  [
    "pem_file" => "/etc/certs/client.pem",
    "ca_file" => "/etc/certs/ca.pem",
  ]
);
?>

<!-- End x509 connection -->