package com.example.demo;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

@Controller
public class controller {
	
	private String message = "VCS";
	
	 @RequestMapping(value = { "/", "/hello" }, method = RequestMethod.GET)
	    public String index(Model model) {
	 
	        model.addAttribute("message", message);
	 
	        return "hello";
	    }
}
