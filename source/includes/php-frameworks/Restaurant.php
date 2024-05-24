<?php

declare(strict_types=1);

namespace App\Document;

use DateTime;
use Doctrine\Common\Collections\ArrayCollection;
use Doctrine\Common\Collections\Collection;
use Doctrine\ODM\MongoDB\Mapping\Annotations as MongoDB;
use Doctrine\ODM\MongoDB\Mapping\Annotations as ODM;
use Doctrine\ODM\MongoDB\Types\Type;

#[
    MongoDB\Document(collection: 'restaurants')
]

class Restaurant
{
    #[ODM\Id]
    public  $id;

    #[ODM\Field(type: Type::STRING)]
    public string $name;

    #[ODM\Field(type: Type::STRING)]
    public string $borough;

    #[ODM\Field(type: Type::STRING)]
    public int $cuisine;

}