// begin scram connection
package main

import (
	"context"
	"fmt"
	"log"
	"go.mongodb.org/mongo-driver/mongo"
	"go.mongodb.org/mongo-driver/mongo/options"
	"go.mongodb.org/mongo-driver/bson"
)

func main() {

	ctx, _ := context.WithTimeout(context.Background(), 10*time.Second)
	client, err := mongo.Connect(ctx, options.Client().ApplyURI(
	   "mongodb+srv://<username>:<password>@<cluster-url>/test?retryWrites=true&w=majority"
	))
	if err != nil { log.Fatal(err) }

	collection := client.Database("testDB").Collection("testCol")
	docCount, err := collection.CountDocuments(ctx, bson.D{})
	if err != nil { log.Fatal(err) }
	fmt.Println(docCount)
}
// end scram connection 