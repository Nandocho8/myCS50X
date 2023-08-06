<body class="">


<h1>Lab 2: Scrabble</h1>

<div class="alert alert-warning" data-alert="warning" role="alert"><p>You are welcome to collaborate with one or two classmates on this lab, though it is expected that every student in any such group contribute equally to the lab.</p></div>

<p>Determine which of two Scrabble words is worth more.</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./scrabble
Player 1: COMPUTER
Player 2: science
Player 1 wins!
</code></pre></div></div>


<h2>Background</h2>

<p>In the game of Scrabble, players create words to score points, and the number of points is the sum of the point values of each letter in the word.</p>

<div class="bootstrap-table bootstrap5">
<div class="fixed-table-toolbar"></div>

<div class="fixed-table-container" style="padding-bottom: 0px;">
<div class="fixed-table-header" style="display: none;"><table></table></div>
<div class="fixed-table-body">
<div class="fixed-table-loading table table-bordered table-striped" style="top: 50px;">
<span class="loading-wrap">
<span class="loading-text">Loading, please wait</span>
<span class="animation-wrap"><span class="animation-dot"></span></span>
</span>

</div>
<table class="table table-bordered table-striped" style="margin-top: 0px;">
<thead style=""><tr><th style="" data-field="0"><div class="th-inner "><div style="text-align: left">A</div></div><div class="fht-cell"></div></th><th style="" data-field="1"><div class="th-inner "><div style="text-align: left">B</div></div><div class="fht-cell"></div></th><th style="" data-field="2"><div class="th-inner "><div style="text-align: left">C</div></div><div class="fht-cell"></div></th><th style="" data-field="3"><div class="th-inner "><div style="text-align: left">D</div></div><div class="fht-cell"></div></th><th style="" data-field="4"><div class="th-inner "><div style="text-align: left">E</div></div><div class="fht-cell"></div></th><th style="" data-field="5"><div class="th-inner "><div style="text-align: left">F</div></div><div class="fht-cell"></div></th><th style="" data-field="6"><div class="th-inner "><div style="text-align: left">G</div></div><div class="fht-cell"></div></th><th style="" data-field="7"><div class="th-inner "><div style="text-align: left">H</div></div><div class="fht-cell"></div></th><th style="" data-field="8"><div class="th-inner "><div style="text-align: left">I</div></div><div class="fht-cell"></div></th><th style="" data-field="9"><div class="th-inner "><div style="text-align: left">J</div></div><div class="fht-cell"></div></th><th style="" data-field="10"><div class="th-inner "><div style="text-align: left">K</div></div><div class="fht-cell"></div></th><th style="" data-field="11"><div class="th-inner "><div style="text-align: left">L</div></div><div class="fht-cell"></div></th><th style="" data-field="12"><div class="th-inner "><div style="text-align: left">M</div></div><div class="fht-cell"></div></th><th style="" data-field="13"><div class="th-inner "><div style="text-align: left">N</div></div><div class="fht-cell"></div></th><th style="" data-field="14"><div class="th-inner "><div style="text-align: left">O</div></div><div class="fht-cell"></div></th><th style="" data-field="15"><div class="th-inner "><div style="text-align: left">P</div></div><div class="fht-cell"></div></th><th style="" data-field="16"><div class="th-inner "><div style="text-align: left">Q</div></div><div class="fht-cell"></div></th><th style="" data-field="17"><div class="th-inner "><div style="text-align: left">R</div></div><div class="fht-cell"></div></th><th style="" data-field="18"><div class="th-inner "><div style="text-align: left">S</div></div><div class="fht-cell"></div></th><th style="" data-field="19"><div class="th-inner "><div style="text-align: left">T</div></div><div class="fht-cell"></div></th><th style="" data-field="20"><div class="th-inner "><div style="text-align: left">U</div></div><div class="fht-cell"></div></th><th style="" data-field="21"><div class="th-inner "><div style="text-align: left">V</div></div><div class="fht-cell"></div></th><th style="" data-field="22"><div class="th-inner "><div style="text-align: left">W</div></div><div class="fht-cell"></div></th><th style="" data-field="23"><div class="th-inner "><div style="text-align: left">X</div></div><div class="fht-cell"></div></th><th style="" data-field="24"><div class="th-inner "><div style="text-align: left">Y</div></div><div class="fht-cell"></div></th><th style="" data-field="25"><div class="th-inner "><div style="text-align: left">Z</div></div><div class="fht-cell"></div></th></tr></thead>
<tbody><tr data-index="0"><td>1</td><td>3</td><td>3</td><td>2</td><td>1</td><td>4</td><td>2</td><td>4</td><td>1</td><td>8</td><td>5</td><td>1</td><td>3</td><td>1</td><td>1</td><td>3</td><td>10</td><td>1</td><td>1</td><td>1</td><td>1</td><td>4</td><td>4</td><td>8</td><td>4</td><td>10</td></tr></tbody>
</table></div>
<div class="fixed-table-footer"></div>
</div>
<div class="fixed-table-pagination" style="display: none;"></div>
</div><div class="clearfix"></div>

<p>For example, if we wanted to score the word <code class="language-plaintext highlighter-rouge">Code</code>, we would note that in general Scrabble rules, the <code class="language-plaintext highlighter-rouge">C</code> is worth <code class="language-plaintext highlighter-rouge">3</code> points, the <code class="language-plaintext highlighter-rouge">o</code> is worth <code class="language-plaintext highlighter-rouge">1</code> point, the <code class="language-plaintext highlighter-rouge">d</code> is worth <code class="language-plaintext highlighter-rouge">2</code> points, and the <code class="language-plaintext highlighter-rouge">e</code> is worth <code class="language-plaintext highlighter-rouge">1</code> point. Summing these, we get that <code class="language-plaintext highlighter-rouge">Code</code> is worth <code class="language-plaintext highlighter-rouge">3 + 1 + 2 + 1 = 7</code> points.</p>

<h2>Implementation Details</h2>

<p>Complete the implementation of <code class="language-plaintext highlighter-rouge">scrabble.c</code>, such that it determines the winner of a short scrabble-like game, where two players each enter their word, and the higher scoring player wins.</p>

<ul class="fa-ul">
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span>Notice that we’ve stored the point values of each letter of the alphabet in an integer array named <code class="language-plaintext highlighter-rouge">POINTS</code>.
<ul class="fa-ul">
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span>For example, <code class="language-plaintext highlighter-rouge">A</code> or <code class="language-plaintext highlighter-rouge">a</code> is worth 1 point (represented by <code class="language-plaintext highlighter-rouge">POINTS[0]</code>), <code class="language-plaintext highlighter-rouge">B</code> or <code class="language-plaintext highlighter-rouge">b</code> is worth 3 points (represented by <code class="language-plaintext highlighter-rouge">POINTS[1]</code>), etc.</li>
</ul>
</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span>Notice that we’ve created a prototype for a helper function called <code class="language-plaintext highlighter-rouge">compute_score()</code> that takes a string as input and returns an <code class="language-plaintext highlighter-rouge">int</code>. Whenever we would like to assign point values to a particular word, we can call this function. Note that this prototype is required for C to know that <code class="language-plaintext highlighter-rouge">compute_score()</code> exists later in the program.</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span>In <code class="language-plaintext highlighter-rouge">main()</code>, the program prompts the two players for their words using the <code class="language-plaintext highlighter-rouge">get_string()</code> function. These values are stored inside variables named <code class="language-plaintext highlighter-rouge">word1</code> and <code class="language-plaintext highlighter-rouge">word2</code>.</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span>In <code class="language-plaintext highlighter-rouge">compute_score()</code>, your program should compute, using the <code class="language-plaintext highlighter-rouge">POINTS</code> array, and return the score for the string argument. Characters that are not letters should be given zero points, and uppercase and lowercase letters should be given the same point values.
<ul class="fa-ul">
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span>For example, <code class="language-plaintext highlighter-rouge">!</code> is worth <code class="language-plaintext highlighter-rouge">0</code> points while <code class="language-plaintext highlighter-rouge">A</code> and <code class="language-plaintext highlighter-rouge">a</code> are both worth <code class="language-plaintext highlighter-rouge">1</code> point.</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span>Though Scrabble rules normally require that a word be in the dictionary, no need to check for that in this problem!</li>
</ul>
</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span>In <code class="language-plaintext highlighter-rouge">main()</code>, your program should print, depending on the players’ scores, <code class="language-plaintext highlighter-rouge">Player 1 wins!</code>, <code class="language-plaintext highlighter-rouge">Player 2 wins!</code>, or <code class="language-plaintext highlighter-rouge">Tie!</code>.</li>
</ul>

<h3>Walkthrough</h3>

<div class="alert alert-primary" data-alert="primary" role="alert"><p>This video was recorded when the course was still using CS50 IDE for writing code. Though the interface may look different from your codespace, the behavior of the two environments should be largely similar!</p></div>

<iframe allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen="" class="border" data-video="" src="https://video.cs50.io/RtjxxxlN1gc" scrolling="no" id="iFrameResizer0" style="overflow: hidden; height: 456px;"></iframe>

<h3>Hints</h3>

<ul class="fa-ul">
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span>
<p>You may find the functions <code class="language-plaintext highlighter-rouge">isupper()</code> and <code class="language-plaintext highlighter-rouge">islower()</code> to be helpful to you. These functions take in a character as the argument and return a boolean.</p>
</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span>
<p>To find the value at the <code class="language-plaintext highlighter-rouge">n</code>th index of an array called <code class="language-plaintext highlighter-rouge">arr</code>, we can write <code class="language-plaintext highlighter-rouge">arr[n]</code>. We can apply this to strings as well, as strings are arrays of characters.</p>
</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span>
<p>Recall that computers represent characters using ASCII, a standard that represents each character as a number.</p>
</li>
</ul>



<h3>How to Test Your Code</h3>

<p>Your program should behave per the examples below.</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./scrabble
Player 1: Question?
Player 2: Question!
Tie!
</code></pre></div></div>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./scrabble
Player 1: Oh,
Player 2: hai!
Player 2 wins!
</code></pre></div></div>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./scrabble
Player 1: COMPUTER
Player 2: science
Player 1 wins!
</code></pre></div></div>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./scrabble
Player 1: Scrabble
Player 2: wiNNeR
Player 1 wins!
</code></pre></div></div>
</main>
</div>
</div>
</body>