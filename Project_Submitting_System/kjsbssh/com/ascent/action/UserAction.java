//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.action;

import com.ascent.pojo.User;
import com.ascent.pojo.Usergroup;
import com.ascent.service.UserService;
import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;
import java.util.List;
import javax.servlet.http.HttpServletRequest;
import org.apache.struts2.ServletActionContext;

public class UserAction extends ActionSupport {
  private UserService userService;
  private User user;

  public UserAction() {
  }

  public User getUser() {
    return this.user;
  }

  public void setUser(User user) {
    this.user = user;
  }

  public void setUserService(UserService userService) {
    this.userService = userService;
  }

  public String loginCheck() {
    User u = this.userService.loginCheck(this.user);
    if (u != null) {
      if (u.getUsergroup().getGid().equals(1)) {
        System.out.println("starding3");
        ActionContext.getContext().getSession().put("admin", u);
        return "admin_login";
      }

      if (u.getUsergroup().getGid().equals(2)) {
        System.out.println("starding4");
        ActionContext.getContext().getSession().put("expert", u);
        return "expert_login";
      }

      if (u.getUsergroup().getGid().equals(3)) {
        System.out.println("starding5");
        ActionContext.getContext().getSession().put("unit", u);
        return "unit_login";
      }
    }

    return "error";
  }

  public String findUserByPage() {
    HttpServletRequest request = ServletActionContext.getRequest();
    boolean var2 = true;

    int pageno;
    try {
      pageno = request.getParameter("pageno") == null ? 1 : Integer.parseInt(request.getParameter("pageno"));
    } catch (NumberFormatException var8) {
      pageno = 1;
    }

    List<User> users = this.userService.findAllUser(pageno, 3);
    ActionContext context = ActionContext.getContext();
    System.out.println(">>" + this.userService.getTotalCount());
    int size = this.userService.getTotalCount();
    if (size < 3) {
      size = 1;
    } else if (size % 3 != 0) {
      size = size / 3 + 1;
    } else {
      size /= 3;
    }

    int[] count = new int[size];

    for(int i = 0; i < size; ++i) {
      count[i] = i + 1;
    }

    context.put("total", count);
    context.put("users", users);
    return "success";
  }

  public String addUser() {
    String password = "123";
    HttpServletRequest request = ServletActionContext.getRequest();
    String username = request.getParameter("username");
    String usermessage = request.getParameter("select");
    Usergroup usergroup;
    if (usermessage.equals("2")) {
      usergroup = this.userService.findUserGroupById(2);
      this.user.setUsername(username);
      this.user.setPassword(password);
      this.user.setUsergroup(usergroup);
      this.userService.addUser(this.user);
      return "success";
    } else if (usermessage.equals("3")) {
      usergroup = this.userService.findUserGroupById(3);
      this.user.setUsername(username);
      this.user.setPassword(password);
      this.user.setUsergroup(usergroup);
      this.userService.addUser(this.user);
      return "success";
    } else {
      return "error";
    }
  }

  public String deleteUser() {
    HttpServletRequest request = ServletActionContext.getRequest();
    String id = request.getParameter("id");
    int uid = Integer.parseInt(id);
    User u = this.userService.findUserById(uid);
    if (u != null) {
      this.userService.deleteUser(u);
      return "success";
    } else {
      return "error";
    }
  }

  public String displayUpdateUser() {
    HttpServletRequest request = ServletActionContext.getRequest();
    String id = request.getParameter("id");
    int uid = Integer.parseInt(id);
    User u = this.userService.findUserById(uid);
    System.out.println("---------" + u.getUsername());
    if (u != null) {
      ActionContext context = ActionContext.getContext();
      context.put("user", u);
      return "success";
    } else {
      return "error";
    }
  }

  public String updateUser() {
    HttpServletRequest request = ServletActionContext.getRequest();
    String username = request.getParameter("username");
    String password = request.getParameter("password");
    this.user.setUsername(username);
    this.user.setPassword(password);
    this.userService.updateUser(this.user);
    return "success";
  }

  public String showAllExpert() {
    ActionContext context = ActionContext.getContext();
    List<User> experts = this.userService.findAllExpertByGroup(2);
    context.put("experts", experts);
    System.out.println("experts.size(): " + experts.size());
    return "success";
  }

  public String showAllUnit() {
    ActionContext context = ActionContext.getContext();
    List<User> units = this.userService.findAllUnitByGroup(3);
    context.put("units", units);
    System.out.println("units.size(): " + units.size());
    return "success";
  }
}
