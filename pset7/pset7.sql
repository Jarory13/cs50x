-- MySQL dump 10.13  Distrib 5.5.44, for debian-linux-gnu (i686)
--
-- Host: localhost    Database: pset7
-- ------------------------------------------------------
-- Server version	5.5.44-0ubuntu0.14.04.1-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `history`
--

DROP TABLE IF EXISTS `history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `history` (
  `id` int(10) unsigned NOT NULL,
  `action` varchar(6) COLLATE utf8_unicode_ci NOT NULL,
  `symbol` varchar(8) COLLATE utf8_unicode_ci NOT NULL,
  `name` varchar(100) COLLATE utf8_unicode_ci NOT NULL,
  `shares` int(10) unsigned NOT NULL,
  `price` float NOT NULL,
  `timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `history`
--

LOCK TABLES `history` WRITE;
/*!40000 ALTER TABLE `history` DISABLE KEYS */;
INSERT INTO `history` VALUES (6,'Bought','FB','Facebook, Inc.',2,102.19,'2015-10-25 20:48:32'),(6,'Sold','FB','Facebook, Inc.',10,102.19,'2015-10-25 20:49:57'),(6,'Bought','DIS','Walt Disney Company (The) Commo',25,113.52,'2015-10-26 22:21:44'),(20,'Bought','FB','Facebook, Inc.',1,103.77,'2015-10-27 03:54:58'),(20,'Bought','SBUX','Starbucks Corporation',2,63.43,'2015-10-27 03:56:38'),(20,'Bought','FREE','FreeSeas Inc.',1,0.0711,'2015-10-27 03:58:45'),(20,'Bought','FREE','FreeSeas Inc.',1,0.0711,'2015-10-27 03:59:03'),(20,'Bought','FREE','FreeSeas Inc.',1,0.0711,'2015-10-27 04:19:36'),(20,'Sold','FB','Facebook, Inc.',1,103.77,'2015-10-27 04:24:48'),(20,'Bought','FB','Facebook, Inc.',1,103.77,'2015-10-27 04:25:36'),(20,'Sold','FB','Facebook, Inc.',1,103.77,'2015-10-27 04:25:43');
/*!40000 ALTER TABLE `history` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `holdings`
--

DROP TABLE IF EXISTS `holdings`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `holdings` (
  `id` int(10) unsigned NOT NULL,
  `symbol` varchar(10) COLLATE utf8_unicode_ci NOT NULL,
  `shares` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`,`symbol`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `holdings`
--

LOCK TABLES `holdings` WRITE;
/*!40000 ALTER TABLE `holdings` DISABLE KEYS */;
INSERT INTO `holdings` VALUES (1,'TWTR',10),(2,'IPB',10),(3,'GDDY',6),(4,'TMUS',10),(5,'GOOG',5),(6,'$symbol',1),(6,'DIS',25),(6,'FB',4),(6,'FREE',3),(6,'text',2),(7,'MSFT',10),(16,'SBUX',10),(16,'VZ',10),(17,'SBUX',500),(18,'FB',100),(18,'GOOG',100),(20,'FREE',3),(20,'SBUX',2);
/*!40000 ALTER TABLE `holdings` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `email` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `username` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `hash` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `cash` decimal(65,4) unsigned NOT NULL DEFAULT '0.0000',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`),
  UNIQUE KEY `email` (`email`)
) ENGINE=InnoDB AUTO_INCREMENT=21 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'a','belindazeng','$1$50$oxJEDBo9KDStnrhtnSzir0',1000.0000),(2,'b','caesar','$1$50$GHABNWBNE/o4VL7QjmQ6x0',1000.0000),(3,'c','jharvard','$1$50$RX3wnAMNrGIbgzbRYrxM1/',1000.0000),(4,'d','malan','$1$50$lJS9HiGK6sphej8c4bnbX.',1000.0000),(5,'e','rob','$1$HA$l5llES7AEaz8ndmSo5Ig41',1000.0000),(6,'f','skroob','$1$50$euBi4ugiJmbpIbvTTfmfI.',4375.3940),(7,'g','zamyla','$1$50$uwfqB45ANW.9.6qaQ.DcF.',1000.0000),(20,'Jarory13@gmail.com','Jarory','$1$7HX128Za$aUH6NoXv241GkLnZJWaIo1',872.9267);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2015-10-27  0:31:25
