using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class EnemyHealthBar : MonoBehaviour {
    public Slider slider;
    Camera c;
    public Transform target;

    void Start(){
        c = GameObject.FindWithTag("MainCamera").GetComponent<Camera>();
    }

    public void updateHealthBar(float currentHealth, float maxHealth) {
        slider.value = currentHealth / maxHealth;
    }

    void Update() {
        transform.rotation = c.transform.rotation;
        if(target.gameObject.name == "Boss") transform.position = target.position + new Vector3(0, 3.5f, 0);
        else transform.position = target.position + new Vector3(0, 1.0f, 0);

    }
}