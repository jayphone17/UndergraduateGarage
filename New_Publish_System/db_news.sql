/*
Navicat MySQL Data Transfer

Source Server         : zhupengdou
Source Server Version : 50540
Source Host           : localhost:3306
Source Database       : db_news

Target Server Type    : MYSQL
Target Server Version : 50540
File Encoding         : 65001

Date: 2017-09-10 10:19:28
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `t_admin`
-- ----------------------------
DROP TABLE IF EXISTS `t_admin`;
CREATE TABLE `t_admin` (
  `userId` int(11) NOT NULL DEFAULT '0',
  `userName` varchar(255) DEFAULT NULL,
  `userPw` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`userId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of t_admin
-- ----------------------------
INSERT INTO `t_admin` VALUES ('1', '1', '11');

-- ----------------------------
-- Table structure for `t_catelog`
-- ----------------------------
DROP TABLE IF EXISTS `t_catelog`;
CREATE TABLE `t_catelog` (
  `id` varchar(255) NOT NULL DEFAULT '',
  `name1` varchar(255) DEFAULT NULL,
  `del` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of t_catelog
-- ----------------------------
INSERT INTO `t_catelog` VALUES ('2', '社会', 'no');
INSERT INTO `t_catelog` VALUES ('1', '法律', 'no');
INSERT INTO `t_catelog` VALUES ('1505008941427', '2332423', 'yes');

-- ----------------------------
-- Table structure for `t_gonggao`
-- ----------------------------
DROP TABLE IF EXISTS `t_gonggao`;
CREATE TABLE `t_gonggao` (
  `id` varchar(255) NOT NULL DEFAULT '',
  `title` varchar(255) DEFAULT NULL,
  `content` varchar(255) DEFAULT NULL,
  `shijian` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of t_gonggao
-- ----------------------------
INSERT INTO `t_gonggao` VALUES ('1', '国兴而贵师 习近平打造中华民族“梦之队”', '央视网消息：这是我国第三十三个教师节，但今年的教师节显得有些特别。\r\n\r\n　　2017年是“十三五”规划的重要一年，也是供给侧结构性改革的深化之年。稳增长、促改革、调结构、惠民生、防风险各项工作全面推进，脱贫攻坚开始冲刺，医疗教育体制改革成效显著，风清气正的政治生态和绿水青山的生态环境答卷漂亮，创新驱动，信息化、现代化、科技兴国等战略深入人心……距离2020年改革总目标，我们又进了一步，展望实现伟大复兴中国梦，我们离得更近了。而这一切都离不开人才的培养。\r\n\r\n　　国将兴，必贵师而重傅。于个人，师者，传道', '2017-9-10');
INSERT INTO `t_gonggao` VALUES ('2', '揪出2万多问题企业 京津冀及周边大气污染督查升级', '——超半数被检查企业存环境问题\r\n2017年4月开始，环保部从全国抽调5600名环境执法人员，对京津冀及周边传输通道“2+26”城市开展为期一年的大气污染防治强化督查，并密集通报每日督查结果。\r\n“2+26”城市具体为北京、天津市，河北省石家庄、唐山、保定、廊坊、沧州、衡水、邯郸、邢台市，山西省太原、阳泉、长治、晋城市，山东省济南、淄博、聊城、德州、滨州、济宁、菏泽市，河南省郑州、新乡、鹤壁、安阳、焦作、濮阳、开封市。\r\n目前，强化督查已满五个月。据环保部官网9月1日通报显示，4月7日至8月31日，环保部', '2017-9-8');

-- ----------------------------
-- Table structure for `t_liuyan`
-- ----------------------------
DROP TABLE IF EXISTS `t_liuyan`;
CREATE TABLE `t_liuyan` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `title` varchar(255) DEFAULT NULL,
  `content` varchar(255) DEFAULT NULL,
  `shijian` varchar(255) DEFAULT NULL,
  `user_id` varchar(255) DEFAULT NULL,
  `user_name` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of t_liuyan
-- ----------------------------
INSERT INTO `t_liuyan` VALUES ('1', '你好', '这是留言板的内容', '2017-9-10', '1', '张三');
INSERT INTO `t_liuyan` VALUES ('2', '随便来看看', '我在这里很好。', '2017-9-9', '2', '李四');
INSERT INTO `t_liuyan` VALUES ('3', '111', '<p>1111</p>', '2017-9-10 9:44:09', '1', null);
INSERT INTO `t_liuyan` VALUES ('4', '你你你', '<p>你好吗</p>', '2017-9-10 9:45:00', '1', null);
INSERT INTO `t_liuyan` VALUES ('6', '1212121', '12内容', '2017-9-10 10:16:46', '1', null);
INSERT INTO `t_liuyan` VALUES ('7', '2222', '<p><em><strong><a href=\"http://sdfsdf\">qwqw</a></strong></em></p>', '2017-9-10 10:17:36', '1', null);

-- ----------------------------
-- Table structure for `t_news`
-- ----------------------------
DROP TABLE IF EXISTS `t_news`;
CREATE TABLE `t_news` (
  `id` int(23) NOT NULL AUTO_INCREMENT,
  `catelog_id` varchar(255) DEFAULT NULL,
  `title` varchar(255) DEFAULT NULL,
  `content` varchar(255) DEFAULT NULL,
  `shijian` varchar(255) DEFAULT NULL,
  `del` varchar(255) DEFAULT NULL,
  `catelog_name` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of t_news
-- ----------------------------
INSERT INTO `t_news` VALUES ('1', '1', '法院通报“苹果手机拍出27万” 2名恶作剧者被罚3万', '法制网南京9月9日电9月7日，南京市秦淮区人民法院依法在淘宝网司法拍卖平台上公开拍卖一部二手苹果7手机，至次日12时31分收拍时，该部手机落拍价为270550元，拍卖价格被异常拉高，引发网友和媒体广泛关注。鉴于此，秦淮法院对相关情况展开调查，并依法对其中两名参与“恶作剧”的行为人进行了处罚。\r\n经查，此次拍卖的二手苹果7手机起拍价为100元，加价幅度为50元，时间从2017年9月7日10时起，原定至2017年9月8日10时结束，因拍卖过程中不断有人加价，拍卖被延时377次，最终于2017年9月8日12时3', '2017-9-10', 'no', '1');
INSERT INTO `t_news` VALUES ('2', '2', '18号台风“泰利”生成并指向中国！它将是今年首个真正的大台风', '泰利的生成仅比莫兰蒂早一天，从环境、环流等各方面来说，它们都有点像。当然，历史不会简单重复，莫兰蒂也不太可能简单重演。但需要注意，如果去年莫兰蒂再偏南一点，取巴士海峡中线西行登陆广东，那么它受台湾高山的削弱会更小，广东的影响也绝不会弱于厦门，只会更大。因此，广东、福建、台湾的朋友，或者是在9月13-15号要去那里的朋友，应该密切关注泰利台风的动向，做好应对准备。', '2017-9-8', 'no', '2');
INSERT INTO `t_news` VALUES ('3', '1', '11', '<p>23</p>', '2017-9-10 10:01:13', 'yes', '1');

-- ----------------------------
-- Table structure for `t_user`
-- ----------------------------
DROP TABLE IF EXISTS `t_user`;
CREATE TABLE `t_user` (
  `id` int(1) NOT NULL AUTO_INCREMENT,
  `loginname` varchar(30) DEFAULT NULL,
  `loginpw` varchar(30) DEFAULT NULL,
  `name` varchar(30) DEFAULT NULL,
  `sex` varchar(20) DEFAULT NULL,
  `age` varchar(30) DEFAULT NULL,
  `address` varchar(30) DEFAULT NULL,
  `tel` varchar(30) DEFAULT NULL,
  `email` varchar(30) DEFAULT NULL,
  `qq` varchar(30) DEFAULT NULL,
  `del` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of t_user
-- ----------------------------
INSERT INTO `t_user` VALUES ('1', 'zhangsan', '123456', '张三', '男', '20', '广东省西关市区', '1863456723', '673439@qqcom', '3423424', 'no');
INSERT INTO `t_user` VALUES ('2', 'lisi', '123456', '李四', '女', '19', '关东', '34234234', 'w3454@qq.com', '324234', 'no');
INSERT INTO `t_user` VALUES ('3', '23', '11', 'as', '男', '1', '1', '1', '1', '11', 'no');
