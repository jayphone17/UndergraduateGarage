function check(form){
	alert("");
	if(form.oldpassword.value==""){
		alert("���벻��Ϊ�գ�");
		return false;
	}
	if(form.oldpassword.value.length()>6&&form.oldpassword.value.length()<4){
		alter("����������볤�Ȳ��ԣ�");
		form.newPassword.focus();
		return false;
		
	}
	return true;
}
