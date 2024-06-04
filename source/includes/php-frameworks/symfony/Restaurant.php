<?php

declare(strict_types=1);

namespace App\Document;

use Doctrine\Common\Collections\ArrayCollection;
use Doctrine\Common\Collections\Collection;
use Doctrine\ODM\MongoDB\Mapping\Annotations as ODM;
use Doctrine\ODM\MongoDB\Types\Type;

#[ODM\Document(collection: 'restaurants')]
class Restaurant
{
    #[ODM\Field(type: Type::STRING)]
    public ?string $id = null;

    #[ODM\Field(type: Type::STRING)]
    public string $name;

    #[ODM\Field(type: Type::STRING)]
    public string $borough;

    #[ODM\Field(type: Type::STRING)]
    public string $cuisine;
}
