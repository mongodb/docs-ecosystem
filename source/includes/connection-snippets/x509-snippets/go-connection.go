// begin x509 connection
package main

import (
	"context"
	"fmt"
	"log"
	"go.mongodb.org/mongo-driver/mongo"
	"go.mongodb.org/mongo-driver/mongo/options"
)

type Trainer struct {
    Name string
    Age  int
    City string
}

func main() {
	ctx := context.TODO()
	caFilePath := "/etc/certs/mongodb/ca.pem"
	certificateKeyFilePath := "/etc/certs/mongodb/client.pem"

	uri := "mongodb+srv://<cluster-url>/?tlsCAFile=%s&tlsCertificateKeyFile=%s&authMechanism=MONGODB-X509"
	uri = fmt.Sprintf(uri, caFilePath, certificateKeyFilePath)
	clientOpts := options.Client().ApplyURI(uri)

	client, err := mongo.Connect(ctx, clientOpts)
	if err != nil { log.Fatal(err) }
	defer client.Disconnect(ctx)

}
// end x509 connection