DROP DATABASE IF EXISTS `DB`;
CREATE DATABASE `DB`;
USE `DB`;

DROP TABLE IF EXISTS `Occurrences`;
CREATE TABLE `Occurrences` (
  `IdOccurrence` int NOT NULL AUTO_INCREMENT,
  `Name` varchar(100) NOT NULL,
  `Min_probability` double NOT NULL,
  PRIMARY KEY (`IdOccurrence`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;
INSERT INTO `Occurrences` VALUES (1,'Frequent',20),(2,'Probable',10),(5,'Possible',1),(6,'Rare',0.1),(7,'Remote',0);