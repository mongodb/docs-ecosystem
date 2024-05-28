<?php

declare(strict_types=1);

namespace App\Controller;

use App\Document\Restaurant;
use Doctrine\ODM\MongoDB\DocumentManager;
use MongoDB\BSON\Regex;
use Psr\Log\LoggerInterface;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Annotation\Route;

class RestaurantController extends AbstractController
{
    // DocumentManager instance
    private $_documentManager;
    private $_logger;
    /**
     * __construct -
     * 
     * This function is responsible for initializing the RestaurantController class.
     * 
     * @param DocumentManager $_documentManager - The document manager
     * @param LoggerInterface $_logger          - The logger interface
     * 
     * @return void
     */
    public function __construct(DocumentManager $_documentManager, LoggerInterface $_logger)
    {
        $this->_documentManager = $_documentManager;
        $this->_logger          = $_logger;
    }

    #[Route('/', name: 'restaurant_index', methods: ['GET'])]
    public function index(Request $request): Response
    {   
        return $this->render('restaurant/index.html.twig');
    }

    #[Route('/restaurant/browse', name: 'restaurant_browse', methods: ['GET'])]
    public function browse(Request $request): Response
    {

        $restaurantRepository = $this->_documentManager->getRepository(Restaurant::class);
        $queryBuilder = $restaurantRepository->createQueryBuilder();

        $restaurants = $queryBuilder
                ->field('borough')->equals('Queens')
                ->field('name')->equals(new Regex('Moon', 'i'))
                ->getQuery()
                ->execute();

        return $this->render('restaurant/browse.html.twig', ['restaurants' => $restaurants]);
    }

}