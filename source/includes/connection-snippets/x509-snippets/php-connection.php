<!-- Begin x509 connection -->
<?php
$subject = "mongodb+srv://<your_subject>"; // mongodb+srv://CN=<host>,OU=TestClientCertificateOrgUnit,O=TestClientCertificateOrg,L=TestClientCertificateLocality,ST=TestClientCertificateState,C=US
$manager = new MongoDB\Driver\Manager($subject + "@<cluster-url>/?ssl=true&authMechanism=MONGODB-X509", [], ["pem_file" => "/etc/certs/mongodb/client.pem", "ca_file" => "/etc/certs/mongodb/ca.pem", ]);
?>
<!-- End x509 connection -->
