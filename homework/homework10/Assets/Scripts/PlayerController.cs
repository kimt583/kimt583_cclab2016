using UnityEngine;
using UnityEngine.UI;
using System.Collections;


public class PlayerController : MonoBehaviour {


	public float speed;
	public Text countGain;
	public Text countRemain;

	public Text timeCount;
	public float timeLeft;

	public Text winText;
	public GameObject winPanel;


	public bool startButtonStatus=false;

	public Text gameOverText;
	public GameObject gameOverPanel;

	private Rigidbody rb;
	private int count;

	// Use this for initialization
	void Start () {
		rb = GetComponent<Rigidbody> ();
		count = 0;
		timeLeft = 15f;
		SetCountText ();
		winText.text = "";
		winPanel.SetActive(false);
		gameOverText.text = "";
		gameOverPanel.SetActive(false);
		timeCount.text = "Time: 00";
	}
	
	// Call just before cal physics
	void FixedUpdate () {
		
			float moveHorizontal = Input.GetAxis ("Horizontal");
			float moveVertical = Input.GetAxis ("Vertical");
		if (startButtonStatus==true) {

			timeLeft -= Time.deltaTime;
			timeCount.text = "Time: " + timeLeft.ToString("00");

			Vector3 movement = new Vector3 (moveHorizontal, 0.0f, moveVertical);

			rb.AddForce (movement * speed * 1.5f);

			if (timeLeft < 0 && count!=8) {
				GameOver();
			}
		}

	}

	void OnTriggerEnter(Collider other){

		if (other.gameObject.CompareTag ("Pick Up")) {
			other.gameObject.SetActive (false);
			count = count + 1;
			SetCountText ();
		}	
	}

	void SetCountText()
	{
		countGain.text = "Gain: " + count.ToString ();
		countRemain.text = "Remain: " + (8-count).ToString ();
		if (count == 8) {
			winText.text = "You Win";
			winPanel.SetActive(true);
			timeLeft = 0;
			startButtonStatus = false;
		}
	}

	public void StartButton()
	{
		startButtonStatus = true;
	}

	void GameOver()
	{
		gameOverText.text = "Game Over";
		gameOverPanel.SetActive(true);

		timeLeft = 0;
		startButtonStatus = false;


	}
}
