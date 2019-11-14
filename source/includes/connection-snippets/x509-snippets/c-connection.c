// begin x509 connection
#include <mongoc/mongoc.h>

mongoc_client_t * client;
mongoc_database_t * database;
mongoc_collection_t * collection;
bson_t * command, reply, * insert;
bson_error_t error;
char * str;
bool retval;

mongoc_init();

const mongoc_ssl_opt_t * ssl_default = mongoc_ssl_opt_get_default();
mongoc_ssl_opt_t ssl_opts = {
  0
};

memcpy( & ssl_opts, ssl_default, sizeof ssl_opts);

ssl_opts.pem_file = "/etc/certs/mongodb/client.pem";
ssl_opts.ca_file = "/etc/certs/mongodb/ca.pem";
ssl_opts.weak_cert_validation = false;
ssl_opts.allow_invalid_hostname = false;

char subject[] = "mongodb://<your_subject>"; // mongodb://CN%3DChris%2COU%3DTestClientCertificateOrgUnit%2CO%3DEducationClientCertificate%2CL%3DTestClientCertificateLocality%2CST%3DTestClientCertificateState%2CC%3DUS

char uri[] = strcat(subject, "@localmongo1/?authMechanism=MONGODB-X509")
client = mongoc_client_new(uri);
mongoc_client_set_ssl_opts(client, & ssl_opts);

mongoc_client_set_appname(client, "mongoc-example");
database = mongoc_client_get_database(client, "test");
mongoc_client_destroy(client);
mongoc_cleanup();

// end x509 connection 