//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.serviceImpl;

import com.ascent.dao.UserDao;
import com.ascent.pojo.User;
import com.ascent.pojo.Usergroup;
import com.ascent.service.UserService;
import java.util.List;

public class UserServiceImpl implements UserService {
  private UserDao userdao;

  public UserServiceImpl() {
  }

  public void addUser(User user) {
    this.userdao.addUser(user);
  }

  public void deleteUser(User user) {
    this.userdao.deleteUser(user);
  }

  public List<User> findAllUser(int pageno, int maxrows) {
    List<User> users = this.userdao.findAllUser(pageno, maxrows);
    return users;
  }

  public User findUserById(Integer id) {
    User user = this.userdao.findUserById(id);
    return user;
  }

  public User loginCheck(User user) {
    User u = this.userdao.loginCheck(user);
    return u;
  }

  public void updateUser(User user) {
    this.userdao.updateUser(user);
  }

  public void setUserdao(UserDao userdao) {
    this.userdao = userdao;
  }

  public int getTotalCount() {
    int count = this.userdao.getTotalCount();
    return count;
  }

  public Usergroup findUserGroupById(int id) {
    Usergroup group = this.userdao.findUserGroupById(id);
    return group;
  }

  public List<User> findAllExpertByGroup(Integer id) {
    List<User> experts = this.userdao.findAllExpertByGroup(id);
    return experts;
  }

  public List<User> findAllUnitByGroup(Integer id) {
    List<User> units = this.userdao.findAllUnitByGroup(id);
    return units;
  }
}
