// begin x509 connection
#include <mongoc/mongoc.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  mongoc_collection_t *collection;
  mongoc_client_t *client;
  int64_t count;

  mongoc_init();

  client = mongoc_client_new(
      "mongodb+srv://<cluster-url>/"
      "test?authSource=$external&tlsCertificateKeyFile=/etc/certs/mongodb/"
      "client.pem&retryWrites=true&w=majority&authMechanism=MONGODB-X509");

  collection = mongoc_client_get_collection(client, "testDB", "testCol");
  bson_t filter = BSON_INITIALIZER;
  count = mongoc_collection_count_documents(collection, &filter, NULL, NULL,
                                            NULL, NULL);
  if (count == -1) {
    printf("error occurred with count_documents");
  } else {
    printf("%" PRId64 " documents counted.\n", count);
  }
  bson_destroy(&filter);
  mongoc_collection_destroy(collection);
  mongoc_client_destroy(client);
  mongoc_cleanup();

  return 0;
}
// end x509 connection