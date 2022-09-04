-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Dec 17, 2021 at 04:16 PM
-- Server version: 10.1.38-MariaDB
-- PHP Version: 7.3.2

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `miroslav_331_prog_language`
--

-- --------------------------------------------------------

--
-- Table structure for table `prog_language`
--

CREATE TABLE `prog_language` (
  `id` int(11) NOT NULL,
  `language` varchar(50) COLLATE utf8_bin NOT NULL,
  `creator` varchar(50) COLLATE utf8_bin NOT NULL,
  `dateCreated` year(4) NOT NULL,
  `Rate2021` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Dumping data for table `prog_language`
--

INSERT INTO `prog_language` (`id`, `language`, `creator`, `dateCreated`, `Rate2021`) VALUES
(1, 'PHP', 'Rasmus Lerdorf', 1994, 1.5),
(2, 'JAVASCRIPT', 'Brendan Eich', 1995, 2.3),
(3, 'C++', 'Bjarne Stroustrup', 1985, 7.73),
(4, 'PYTHON', 'Guido van Rossum', 1991, 12.9),
(5, 'C', 'Dennis Ritchie', 1972, 11.8),
(6, 'SQL', 'ISO/IEC', 1974, 1.79),
(7, 'KOTLIN', 'JetBrains', 2010, 0.57),
(8, 'JAVA', 'James Gosling', 1996, 10.12),
(9, 'ASSEMBLY', 'David Wheeler', 1940, 2.25),
(10, 'C#', 'Anders Hejlsberg', 2000, 6.4),
(11, 'POWERSHELL', 'Microsoft', 2006, 0.22),
(12, 'ACTIONSCRIPT', 'Gary Grossman', 1998, 0.16),
(13, 'LUA', 'Roberto Ierusalimschy', 1993, 0.4),
(14, 'BASH', 'Brian Fox', 1989, 0.15),
(28, 'HELLO', 'Unnamed', 1934, 3);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `prog_language`
--
ALTER TABLE `prog_language`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `prog_language`
--
ALTER TABLE `prog_language`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=30;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
