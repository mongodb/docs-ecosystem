// begin x509 connection
package main

import (
	"context"
	"fmt"
	"log"
	"time"
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
	caFilePath := "ca.pem"
	certificateKeyFilePath := "client.pem"

	uri := "mongodb://localhost:27017/?tlsCAFile=%s&tlsCertificateKeyFile=%s&authMechanism=MONGODB-X509"
	uri = fmt.Sprintf(uri, caFilePath, certificateKeyFilePath)
	clientOpts := options.Client().ApplyURI(uri).SetServerSelectionTimeout(2 * time.Second)

	client, err := mongo.Connect(ctx, clientOpts)
	if err != nil {
		log.Fatal(err)
	}

	collection := client.Database("test").Collection("stuff")
	rec := Trainer{"A", 10, "Town"}
	insertResult, err := collection.InsertOne(context.TODO(), rec)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("Inserted a single document: ", insertResult.InsertedID)
	
	defer client.Disconnect(ctx)

	if err = client.Ping(ctx, nil); err != nil {
		log.Fatal(err)
	}
}
// end x509 connection