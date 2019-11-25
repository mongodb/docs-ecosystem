// begin x509 connection
package main

import (
	"context"
	"fmt"
	"log"
	"go.mongodb.org/mongo-driver/mongo"
	"go.mongodb.org/mongo-driver/mongo/options"
)

func main() {
	ctx := context.TODO()
	certificateKeyFilePath := "/etc/certs/mongodb/client.pem"
	uri := "mongodb+srv://<cluster-url>/test?authSource=$external&tlsCertificateKeyFile=%s&authMechanism=MONGODB-X509"
	uri = fmt.Sprintf(uri, certificateKeyFilePath)
	clientOpts := options.Client().ApplyURI(uri)

	client, err := mongo.Connect(ctx, clientOpts)
	if err != nil { log.Fatal(err) }


	collection := client.Database("testDB").Collection("testCol")
	docCount, err := collection.CountDocuments(ctx, nil, nil )
	fmt.Println(docCount)

	defer client.Disconnect(ctx)
}
// end x509 connection 