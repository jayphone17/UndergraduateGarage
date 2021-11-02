//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.service;

import com.ascent.pojo.User;
import com.ascent.pojo.Usergroup;
import java.util.List;

public interface UserService {
  void addUser(User var1);

  void deleteUser(User var1);

  void updateUser(User var1);

  User findUserById(Integer var1);

  List<User> findAllUser(int var1, int var2);

  User loginCheck(User var1);

  int getTotalCount();

  Usergroup findUserGroupById(int var1);

  List<User> findAllExpertByGroup(Integer var1);

  List<User> findAllUnitByGroup(Integer var1);
}
