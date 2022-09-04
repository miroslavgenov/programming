-- phpMyAdmin SQL Dump
-- version 4.7.4
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Dec 29, 2018 at 11:29 AM
-- Server version: 10.1.30-MariaDB
-- PHP Version: 7.2.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `users`
--

-- --------------------------------------------------------

--
-- Table structure for table `data`
--

CREATE TABLE `data` (
  `id` int(11) NOT NULL,
  `name` varchar(30) NOT NULL,
  `email` varchar(20) NOT NULL,
  `created_at` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `data`
--

INSERT INTO `data` (`id`, `name`, `email`, `created_at`) VALUES
(1, 'Максим', 'maksi@mail.bg', '2017-12-20 14:43:23'),
(2, 'Мария', 'mm@abv.bg', '2017-12-06 19:16:51'),
(3, 'Иван', 'ivan@abv.bg', '2017-12-06 19:17:00'),
(4, 'Кирил', 'kkk@abv.bg', '2017-12-06 19:23:02'),
(5, 'Елена', 'elen@mail.bg', '2017-12-20 14:41:29'),
(6, 'Калина', 'kali@abv.bg', '2017-12-20 15:55:53'),
(7, 'Цветелина', 'tsveti@mail.bg', '2017-12-21 06:49:09'),
(8, 'Мирем', 'mirem@abv.bg', '2017-12-21 07:45:23'),
(9, 'Ели', 'eli@abv.bg', '2017-12-30 15:49:39'),
(10, 'Мартин', 'marti@mail.bg', '2018-12-13 08:57:19'),
(11, 'Сияна', 'sisi@mail.bg', '2018-12-21 07:31:32'),
(12, 'Марина', 'marina@mail.bg', '2018-12-29 09:26:20');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `data`
--
ALTER TABLE `data`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `data`
--
ALTER TABLE `data`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
