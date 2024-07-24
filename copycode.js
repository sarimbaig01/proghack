function loadCode() {
    const codeContainer = document.querySelector('.code-container');
    const fileName = codeContainer.getAttribute('data-filename');

    fetch(fileName)
        .then(response => response.text())
        .then(code => {
            const codeElement = document.getElementById('cpp-code');
            codeElement.textContent = code; // Use textContent to prevent HTML interpretation
            Prism.highlightElement(codeElement); // Highlight the code after adding it
        })
        .catch(error => console.error('Error loading the code:', error));
}

function copyCode() {
    const button = document.querySelector('.copy-btn');
    const originalText = button.textContent;
    const code = document.getElementById('cpp-code').textContent.trim();
    
    navigator.clipboard.writeText(code).then(function() {
        button.textContent = '✓ Copied';
        setTimeout(function() {
            button.textContent = originalText;
        }, 3000);
    }, function(err) {
        console.error('Failed to copy: ', err);
    });
}

document.addEventListener('DOMContentLoaded', function() {
    loadCode();
    document.querySelector('.copy-btn').addEventListener('click', copyCode);
});

// Example function to handle navigation
document.querySelectorAll('.back-link').forEach(link => {
    link.addEventListener('click', function(event) {
        event.preventDefault();
        window.location.href = link.href; // Navigate to the specified URL
    });
});
